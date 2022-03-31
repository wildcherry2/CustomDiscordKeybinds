/**
 * @name BindLeaveVC
 * @invite undefined
 * @authorLink undefined
 * @donate undefined
 * @patreon undefined
 * @website 
 * @source 
 */
/*@cc_on
@if (@_jscript)
    
    // Offer to self-install for clueless users that try to run this directly.
    var shell = WScript.CreateObject("WScript.Shell");
    var fs = new ActiveXObject("Scripting.FileSystemObject");
    var pathPlugins = shell.ExpandEnvironmentStrings("%APPDATA%\\BetterDiscord\\plugins");
    var pathSelf = WScript.ScriptFullName;
    // Put the user at ease by addressing them in the first person
    shell.Popup("It looks like you've mistakenly tried to run me directly. \n(Don't do that!)", 0, "I'm a plugin for BetterDiscord", 0x30);
    if (fs.GetParentFolderName(pathSelf) === fs.GetAbsolutePathName(pathPlugins)) {
        shell.Popup("I'm in the correct folder already.", 0, "I'm already installed", 0x40);
    } else if (!fs.FolderExists(pathPlugins)) {
        shell.Popup("I can't find the BetterDiscord plugins folder.\nAre you sure it's even installed?", 0, "Can't install myself", 0x10);
    } else if (shell.Popup("Should I copy myself to BetterDiscord's plugins folder for you?", 0, "Do you need some help?", 0x34) === 6) {
        fs.CopyFile(pathSelf, fs.BuildPath(pathPlugins, fs.GetFileName(pathSelf)), true);
        // Show the user where to put plugins in the future
        shell.Exec("explorer " + pathPlugins);
        shell.Popup("I'm installed!", 0, "Successfully installed", 0x40);
    }
    WScript.Quit();

@else@*/

const spawn = require('child_process').execFile;
var child;

module.exports = (() => {
    const config = {"main":"index.js","info":{"name":"BindLeaveVC","authors":[{"name":"wildcherry","discord_id":"200336755235356672","github_username":"wildcherry","twitter_username":"wildcherryrl"}],"version":"1.0.0","description":"Press [End] to leave a voice chat.","github":"","github_raw":""},"changelog":[{"title":"Initial version","items":["Initial commit","Added changelog"]}]};

    return !global.ZeresPluginLibrary ? class {
        constructor() {this._config = config;}
        getName() {return config.info.name;}
        getAuthor() {return config.info.authors.map(a => a.name).join(", ");}
        getDescription() {return config.info.description;}
        getVersion() {return config.info.version;}
        load() {
            BdApi.showConfirmationModal("Library Missing", `The library plugin needed for ${config.info.name} is missing. Please click Download Now to install it.`, {
                confirmText: "Download Now",
                cancelText: "Cancel",
                onConfirm: () => {
                    require("request").get("https://rauenzi.github.io/BDPluginLibrary/release/0PluginLibrary.plugin.js", async (error, response, body) => {
                        if (error) return require("electron").shell.openExternal("https://betterdiscord.net/ghdl?url=https://raw.githubusercontent.com/rauenzi/BDPluginLibrary/master/release/0PluginLibrary.plugin.js");
                        await new Promise(r => require("fs").writeFile(require("path").join(BdApi.Plugins.folder, "0PluginLibrary.plugin.js"), body, r));
                    });
                }
            });
        }
        start() {}
        stop() {}
    } : (([Plugin, Api]) => {
        const plugin = (Plugin, Library,DiscordModules) => {
    return class BindLeaveVC extends Plugin {
        
        onStart() {
            console.log("BindLeaveVC started");
            child = spawn(BdApi.Plugins.folder + '\\dbind.exe');
            child.stdout.on('data',(data)=>{
                if(data.toString().includes("END")) ZeresPluginLibrary.DiscordModules.ChannelActions.disconnect();
                //else if (data.toString().includes("PGDOWN + NUMPAD7")) BdApi.findModuleByProps("sendMessage").sendMessage("716744866876620920", {content: "!q"});
                //else if (data.toString().includes("PGDOWN + NUMPAD8")) BdApi.findModuleByProps("sendMessage").sendMessage("716744866876620920", {content: "!leave"});;
            });
            console.log(child.pid);
        }

        onStop() {
            console.log(child.pid);
            child.kill();
        }

        
    };
};
        return plugin(Plugin, Api);
    })(global.ZeresPluginLibrary.buildPlugin(config));
})();
/*@end@*/