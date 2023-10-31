#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>

struct Member
{
    std::string name;
    int height;
    int yearOfJoining;

    Member(std::string name, int height, int yearOfJoining) : name(name), height(height), yearOfJoining(yearOfJoining){};

};

class AGHRacingTeam
{
public:
// ###################################################################################################################################################################################
    // PROPER SHALLOW COPY
    // TODO: https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
    // TODO: https://stackoverflow.com/questions/2657810/deep-copy-vs-shallow-copy
    // TODO: https://stackoverflow.com/questions/2657810/deep-copy-vs-shallow-copy
    // TODO: https://www.google.com/search?client=firefox-b-d&q=shallow+vs+deep+copy+C%2B%2B#fpstate=ive&vld=cid:74b8869d,vid:C_nLA3hfw8E,st:0
    // TODO: https://www.youtube.com/watch?v=tbtFKuTcZKs
//    AGHRacingTeam(const AGHRacingTeam &otherAGHRacingTeam) : members(std::make_shared<std::vector<Member>>(otherAGHRacingTeam.members->begin(), otherAGHRacingTeam.members->end())) {}
//
//    AGHRacingTeam(const std::vector<Member>& newMembers) {
//        for (const auto& member : newMembers) {
//            if (isValidMember(member.name, member.height, member.yearOfJoining)) {
//                members->push_back(member);
//            }
//        }
//    }
    AGHRacingTeam(): members(std::make_shared<std::vector<Member>>()) {}
    AGHRacingTeam(const AGHRacingTeam &other) = default;
// ###################################################################################################################################################################################

//    AGHRacingTeam(){}

    // Shallow Copy Constructor - could lead to memory leaks and unexpected errors!!
//    AGHRacingTeam(const AGHRacingTeam &otherAGHRacingTeam) : members(otherAGHRacingTeam.members) {}
//    AGHRacingTeam(const AGHRacingTeam &otherAGHRacingTeam){
//        members = otherAGHRacingTeam.members;
//    }

//    AGHRacingTeam(const std::vector<Member>& newMembers) {
//        for (const auto& member : newMembers) {
//            if (isValidMember(member)) {
//                members.push_back(member);
//            }
//        }
//    }

    bool isValidMember(std::string name, int height, int yearOfJoining){
        bool shouldAdd = true;
        if (!(typeid(height) == typeid(int) && typeid(yearOfJoining) == typeid(int) && typeid(name) == typeid(std::string))) {  // && !name.empty()
            throw std::invalid_argument("Invalid input data. Check data types and non-empty string.");
        }
        if(!(100 <= height && height <= 250)) {
            shouldAdd = false;
        }
        if(!(2000 <= yearOfJoining && yearOfJoining <= 2023)){
            shouldAdd = false;
        }
        if(name.length() >= 20){
            shouldAdd = false;
        }
        if(!std::isupper(name[0])){
            shouldAdd = false;
        }
        if (!std::all_of(name.begin(), name.end(), ::isalnum)) {
            shouldAdd = false;
        }

        return shouldAdd;
    }

//    std::vector<Member> getMembers() { return members; }\
// ###################################################################################################################################################################################
    // PROPER SHALLOW COPY
    std::vector<Member> getMembers() { return *members; }
// ###################################################################################################################################################################################

    /**
     * Add new member to the members array only when input is valid.
     */
    void addMember(std::string name, int height, int yearOfJoining);

    /**
     * Return list of names sorted by height of team members in ascending order.
     */
    std::vector<std::string> getMembersSortedByHeightAsc();

    /**
     * Return number of members who joined the team in leap year.
     */
    int getNumberOfMembersWhoJoinedInLeapYear();

    /**
     * Return maximum number of members who joined in the same year.
    */
    int getMaxNumberOfJoinedInTheSameYear();

private:
//    std::vector<Member> members;
// ###################################################################################################################################################################################
    // PROPER SHALLOW COPY
    std::shared_ptr<std::vector<Member>> members;
// ###################################################################################################################################################################################
};