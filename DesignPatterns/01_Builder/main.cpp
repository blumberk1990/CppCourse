#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

struct HtmlBuilder;

class HtmlElement 
{
    private:
        friend class HtmlBuilder;
        std::string name;
        std::string text;

        std::vector<HtmlElement> elements;
        const size_t indent_size = 2;

        HtmlElement() {};
        HtmlElement(const std::string & name, const std::string& text) 
                    : name(name), text(text) {};

    public:
        std::string str(int indent = 0) const {
            std::ostringstream oss;
            std::string i(indent_size*indent, ' ');

            oss << i << "<" << this->name << ">" << std::endl;

            if(this->text.size() > 0) {
                oss << std::string(indent_size*(indent + 1), ' ') << text << std::endl;
            }

            for(const auto& element : this->elements) {
                oss << element.str(indent+1);
            }

            oss << i << "</" << this->name << ">" << std::endl;
            return oss.str();
        }

        static std::unique_ptr<HtmlBuilder> build(const std::string& rootName) {
            return std::make_unique<HtmlBuilder>(rootName);
        }


};

class HtmlBuilder
{
    private:
        HtmlElement root;
    
    public:
        HtmlBuilder(std::string rootName) { root.name = rootName; }
        /**
         * @brief  Method is dedicated for inserting child element of the root html element.
         * 
         * @param childName 
         * @param childText 
         * @return HtmlBuilder& returning reference give us possibility to work in chain.
         *         What is called fluent interface.
         */
        HtmlBuilder& _addChildRef(std::string childName, std::string childText) {
            HtmlElement element{childName, childText};
            root.elements.emplace_back(element);
            return *this;
        }
        /**
         * @brief  Method is dedicated for inserting child element of the root html element.
         * 
         * @param childName 
         * @param childText 
         * @return HtmlBuilder* returning pointer give us possibility to work in chain.
         *         What is called fluent interface.
         */
        HtmlBuilder* _addChildPtr(std::string childName, std::string childText) {
            HtmlElement element(childName, childText);
            root.elements.emplace_back(element);
            return this;
        }
        std::string str() { return root.str(); }

        operator HtmlElement() const { return root; }
};

int main() 
{

    /*this is how it could be done without pattern.*/
    std::string words[] = {"hello", "world"};
    std::ostringstream oss;

    std::cout << "Perform test 1. basic problem to solve." << std::endl;
    oss << "<ul>\n";
    for (auto word : words) {
        oss << "    <li>" << word << "</li>\n";
    }
    oss << "</ul>\n";
    printf(oss.str().c_str());

/* Not valid since constructor is private
    std::cout << "\nPerform test 2. Implement just the struct/class of the OOP." << std::endl;
    HtmlElement list{"ul", ""};
    for (auto word: words) {
        list.elements.emplace_back(HtmlElement{"li", word});
    }
    printf(list.str().c_str());
*/
    std::cout << "\nPerform test 3. Implement simple builder." << std::endl;
    HtmlBuilder builder("ul");
    for (auto word: words) {
        builder._addChildRef("li", word);
    }
    std::cout << builder.str() << std::endl;

    std::cout << "\nPerform test 4. Implement fluent interface with usage of reference." << std::endl;
    HtmlBuilder builder2{ "ul" };
    builder2._addChildRef("li", words[0])._addChildRef("li", words[1]);
    std::cout << builder2.str() << std::endl;

    std::cout << "\nPerform test 5. Implement fluent interface with usage of ptr." << std::endl;
    HtmlBuilder* builder3 = new HtmlBuilder{ "ul" };
    builder3->_addChildPtr("li", words[0])->_addChildPtr("li", words[1]);
    std::cout << builder3->str() << std::endl;

    std::cout << "\nPerform test 6. force user to use htmlBuilder." << std::endl;
    auto builder4 = HtmlElement::build("ul");
    builder4->_addChildPtr("li", words[0])->_addChildPtr("li", words[1]);
    std::cout << builder4->str() << std::endl;

    std::cout << "\nPerform test 7. force user to use htmlBuilder." << std::endl;
    HtmlElement elem = HtmlElement::build("ul")->_addChildRef("li", words[0])._addChildRef("li", words[1]);//->_addChildPtr("li", words[0])->_addChildPtr("li", words[1]);
    std::cout << elem.str() << std::endl;

}