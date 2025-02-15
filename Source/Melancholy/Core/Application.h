#pragma once

namespace Melancholy {

    class Application {
    public:
        virtual ~Application() = default;

        /**
         * This runs the application calling it does most engine related stuff
         * automatically
         * 
         * @returns [bool] if the application finished succesfully or encountered an error
         *      and must close
         */
        bool Run();

    protected:
        
        /**
         * This is one of the first things to be called in [Run()]...
         * Used to create basic gameplay elements; [Define the scene, Load assets / configurations, etc.]
         * 
         * @return [bool] If everything initialisd okay, return true, if there's an error and the 
         *      program is not able to create / shouldnt create, return false to close
         */
        virtual bool Create() = 0;
    };

}