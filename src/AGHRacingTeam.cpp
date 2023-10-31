#include "../include/AGHRacingTeam.h"

#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <map>



void AGHRacingTeam::addMember(std::string name, int height, int yearOfJoining)
{
    if(isValidMember(name, height, yearOfJoining)) {
//        members.emplace_back(std::move(name), height, yearOfJoining);
        members->emplace_back(std::move(name), height, yearOfJoining);
    }
}

std::vector<std::string> AGHRacingTeam::getMembersSortedByHeightAsc()
{
//    if(members.empty()){
    if(members->empty()){
        throw std::runtime_error("No members in the team");
    }
    std::vector<std::pair<int, std::string>> temp; // aka #include <map>, & not coping elements
//    for (const auto &member : members) {
    for (const auto &member : *members) {
        temp.emplace_back(member.height, member.name);
    }

    std::sort(temp.begin(), temp.end());

    std::vector<std::string> sortedNames;
    for (const auto &item : temp) {
        sortedNames.push_back(item.second);
    }

    return sortedNames;
}
//std::vector<std::string> AGHRacingTeam::getMembersSortedByHeightAsc() {
//    auto sortedMembers = *m_members;
//    std::ranges::sort(sortedMembers, {}, &Member::height);
//    return sortedMembers
//           | std::ranges::views::transform(&Member::name)
//           | std::ranges::to<std::vector<std::string>>();
//}


int AGHRacingTeam::getNumberOfMembersWhoJoinedInLeapYear()
{
//    if(members.empty()){
    if(members->empty()){
        throw std::runtime_error("No members in the team");
    }
    int leapJoinCounter = 0;
//    for (const auto &member : members) {
    for (const auto &member : *members) {
        if(member.yearOfJoining % 4 == 0){
            leapJoinCounter++;
        }
    }
    return leapJoinCounter;
}

int AGHRacingTeam::getMaxNumberOfJoinedInTheSameYear()
{
//    if(members.empty()){
    if(members->empty()){
        throw std::runtime_error("No members in the team");
    }

    std::map<int, int> yearNOJoins;
//    for (const auto &member : members) {
    for (const auto &member : *members) {
        yearNOJoins[member.yearOfJoining]++;
    }

    int maxValue = 0;
    for (const auto &yearJoinsPairs : yearNOJoins) {
        if (yearJoinsPairs.second > maxValue) {
            maxValue = yearJoinsPairs.second;
        }
    }

    return maxValue;
}
