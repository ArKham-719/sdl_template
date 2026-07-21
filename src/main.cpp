#include<iostream>
#include<SDL3/SDL.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_sdl3.h>
#include <imgui/backends/imgui_impl_sdlrenderer3.h>
#include <stb/stb_image.h>



int main(int argc , char* argv[])
{
    if(!SDL_Init(SDL_INIT_VIDEO))
    {
            std::cout<<"failed to init sdl\n";
       return -1; 
    }
    SDL_Window* window_ptr = SDL_CreateWindow("first", 800, 800, SDL_WINDOW_RESIZABLE);
    if(!window_ptr){
            std::cout<<"failed to create window\n";
        SDL_Quit();
        return -1;
    }
    SDL_Renderer* renderer_ptr = SDL_CreateRenderer(window_ptr, NULL);
    if(!renderer_ptr){
        std::cout<<"failed to create renderer\n";
        SDL_DestroyWindow(window_ptr);
        SDL_Quit();
        return -1;
    }
    int w, h, channels;
    unsigned char* pixels = stbi_load("T.png", &w, &h, &channels, STBI_rgb_alpha);
    //render target
    SDL_Texture* tex = SDL_CreateTexture(renderer_ptr, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, w, h);
    SDL_UpdateTexture(tex, NULL, pixels, w * 4);
    stbi_image_free(pixels);
      //init imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    ImGui_ImplSDL3_InitForSDLRenderer(window_ptr,  renderer_ptr);
    ImGui_ImplSDLRenderer3_Init(renderer_ptr);
    

    bool running = true;
    while(running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
            ImGui_ImplSDL3_ProcessEvent(&event);
        }
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("screen");
        ImGui::Text("Hello, world");



        ImGui::End();
        ImGui::Begin("iMage");
     
        ImGui::Image((ImTextureID)tex, ImVec2((float)w, (float)h));
        ImGui::End();
        ImGui::Render(); 
        SDL_SetRenderDrawColor(renderer_ptr, 255, 30, 30, 255);
        SDL_RenderClear(renderer_ptr);
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer_ptr);
         SDL_RenderPresent(renderer_ptr);
    }
    ImGui_ImplSDL3_Shutdown();
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer_ptr);
    SDL_DestroyWindow(window_ptr);
    SDL_Quit();

    return 0;
}