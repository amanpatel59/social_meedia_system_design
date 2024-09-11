#include "LikeDecorator.hpp"
#include <iostream>

using namespace std;

LikeDecorator::LikeDecorator(Post* currentPost) : PostDecorator(currentPost),currentPost(currentPost) {}

void LikeDecorator::like(string userWhoInitialized){
    unordered_set<string> currentLikes = currentPost->getLikes();
    for(auto peopleWhoLiked : currentLikes){
        if(peopleWhoLiked == userWhoInitialized){
            cout<<endl<<"User already liked"<<endl;
            cout<<"Press 1 to unlike"<<endl;
            int flag;
            cin>>flag;
            if(flag)unlike(currentLikes,userWhoInitialized);
            return;
        }
    }
    currentLikes.insert(userWhoInitialized);
    currentPost->setLikes(currentLikes);
    cout<<endl<<"You Liked The Post"<<endl;
}

void LikeDecorator::showPostDetails(){
    // PostDecorator::showPostDetails();
    cout<<"Likes : "<<currentPost->getLikes().size()<<endl;
}

void LikeDecorator::unlike(unordered_set<string>&currentLikes , string userWhoInitialized){
    currentLikes.erase(userWhoInitialized);
    currentPost->setLikes(currentLikes);
    cout<<endl<<"You Unliked The Post"<<endl;
}