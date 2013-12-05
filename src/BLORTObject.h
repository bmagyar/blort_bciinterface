#ifndef _H_BLORTOBJECT_H_
#define _H_BLORTOBJECT_H_

#include <bci-interface/DisplayObject/SSVEPStimulus.h>

#include <blort/Tracker/Resources.h>
#include <blort/Tracker/ModelLoader.h>
#include <blort/TomGine/tgCamera.h>
#include <blort/TomGine/tgPose.h>
#include <blort/blort/pal_util.h>

#include <ros/ros.h>

#include <boost/thread.hpp>

#include "BLORTObjectsManager.h"

class BLORTObject : public bciinterface::SSVEPStimulus
{
public:
    BLORTObject(const std::string & object_name, const std::string & filename, int frequency, int screenFrequency, unsigned int wwidth, unsigned int wheight, unsigned int iwidth, unsigned int iheight, BLORTObjectsManager & manager);

    ~BLORTObject();

    virtual void Display(sf::RenderWindow * app, unsigned int frameCount, sf::Clock & clock);

    virtual bool DrawWithGL() { return true; }

    void Update(const TomGine::tgPose & nPose);

    const std::string & getName() { return object_name; }
private:
    /* No copy */
    BLORTObject(const BLORTObject &);
    BLORTObject & operator=(const BLORTObject &);

    BLORTObjectsManager & manager;

    unsigned int wwidth;
    unsigned int wheight;
    unsigned int iwidth;
    unsigned int iheight;
    std::string object_name;
    std::string filename;
    Tracking::TrackerModel * model;
    TomGine::tgCamera camera;
    TomGine::tgPose pose;
    boost::mutex pose_mutex;
    ros::Time last_update;
};

#endif
