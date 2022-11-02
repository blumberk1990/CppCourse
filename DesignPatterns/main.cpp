#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


struct HtmlElement 
{
    std::string name;
    std::string text;

    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;

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
};

struct HtmlBuilder
{
    HtmlElement root;
    
    HtmlBuilder(std::string rootName) { root.name = rootName; }
    /**
     * @brief  Method is dedicated for inserting child element of the root html element.
     * 
     * @param childName 
     * @param childText 
     * @return HtmlBuilder& returning reference gve us possibility to work in chain.
     *         What is called fluent interface.
     */
    HtmlBuilder& _addChildRef(std::string childName, std::string childText) {
        HtmlElement element{childName, childText};
        root.elements.emplace_back(element);
        return *this;
    }

    HtmlBuilder* _addChildPtr(std::string childName, std::string childText) {
        HtmlElement element{childName, childText};
        root.elements.emplace_back(element);
        return this;
    }
    std::string str() { return root.str(); }
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

    std::cout << "\nPerform test 2. Implement just the struct/class of the OOP." << std::endl;
    HtmlElement list{"ul", ""};
    for (auto word: words) {
        list.elements.emplace_back(HtmlElement{"li", word});
    }
    printf(list.str().c_str());

    std::cout << "\nPerform test 3. Implement simple builder." << std::endl;
    HtmlBuilder builder{ "ul" };
    for (auto word: words) {
        builder._addChildRef("li", word);
    }
    std::cout << builder.str() << std::endl;

    std::cout << "\nPerform test 4. Implement fluent interface with usage of reference." << std::endl;
    HtmlBuilder builder2{ "ul" };
    builder2._addChildRef("li", words[0])._addChildRef("li", words[1]);
    std::cout << builder.str() << std::endl;

    std::cout << "\nPerform test 5. Implement fluent interface with usage of ptr." << std::endl;
    HtmlBuilder* builder3 = new HtmlBuilder{ "ul" };
    builder3->_addChildPtr("li", words[0])->_addChildPtr("li", words[1]);
    std::cout << builder.str() << std::endl;

}