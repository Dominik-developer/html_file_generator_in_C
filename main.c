#include <stdio.h>
#include <string.h>

int main() {
    
    // adding tables for data provided by user
    
    // basics
    char title[100];
    char heading[100];
    char paragraph[200];
    
    // photo
    char img_url[100];
    char img_caption[100];
    
    // getting data from user
    
    printf("Enter the title of the page: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; 
    
    
    printf("Enter the heading (h1): ");
    fgets(heading, sizeof(heading), stdin);
    heading[strcspn(heading, "\n")] = '\0';
    
    printf("Enter the paragraph text: ");
    fgets(paragraph, sizeof(paragraph), stdin);
    paragraph[strcspn(paragraph, "\n")] = '\0';
    
    printf("Enter the image URL: ");
    fgets(img_url, sizeof(img_url), stdin);
    img_url[strcspn(img_url, "\n")] = '\0';
    
    printf("Enter the image caption: ");
    fgets(img_caption, sizeof(img_caption), stdin);
    img_caption[strcspn(img_caption, "\n")] = '\0'; // Usuwamy znak nowej linii

    
    // generating html file
    FILE *file = fopen( "index.html", "w"); // opening var file, FILE means it is not number or sth but file
    
    if (file == NULL) {
        printf("Error: Could not create file. \n");
        return 1;   
    }
    
    // adding HTML structure to index.html file
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html>\n");
    fprintf(file, "<head>\n");
    fprintf(file, "    <title>%s</title>\n", title);
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
        
    // tags
    fprintf(file, "    <h1>%s</h1>\n", heading);
    fprintf(file, "    <p>%s</p>\n", paragraph);
        
    // img
    fprintf(file, "    <figure>\n");
    fprintf(file, "        <img src=\"%s\" alt=\"%s\">\n", img_url, img_caption);
    fprintf(file, "        <figcaption>%s</figcaption>\n", img_caption);
    fprintf(file, "    </figure>\n");
        
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");

    printf("Custom HTML page has been written to 'index.html'.\n");

    fclose(file); // closing file
    return 0;
}