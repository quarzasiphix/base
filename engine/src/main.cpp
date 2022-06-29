#define DEV


#include <iostream>
#include <discordOs/discordOs.hpp>

namespace discordOs {
	const char* token = "token" /*put your account token here*/;
	bool bot = false; /*true || false*/

	/*this function gets called on each message received by the client from a user*/
	void on_message(client::message msg)
	{
		msg.command("test", 
			[](client::message msg) {
				msg.respond(&msg, "received test");
				std::cout << "received test" << std::endl;
			}
		);

		msg.command("pong", 
			[](client::message msg) {
				msg.respond(&msg, "ping");
				std::cout << "received pong" << std::endl;
			}
		);

		msg.command("user", 
			[](client::message msg) {
				discord disc;
				if (disc.get_user(msg.param[1]))
					msg.respond(&msg, std::string("```"
						"name: " + disc.fetched_user.username + "#" + disc.fetched.discriminator + "\n" +
						"id: " + disc.fetched_user.id + "\n" + "```" +
						disc.fetched_user.profile_url + "\n"
				));
				else msg.respond(&msg, "```invalid id```");
			}
		);
}


int main()
{
	using namespace discordOs;
	discord discordOs(token, bot);
}