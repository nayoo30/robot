#include "sensor_board_tortuga.h"


//construtor for sensor board, you need to open the sensor board before making an instance of this class. This is to allow multiple instances to talk to the same board. 
SensorBoardTortugaNode::SensorBoardTortugaNode(std::shared_ptr<ros::NodeHandle> n , int rate, int fd, std::string sensor_file): RamNode(n) {
    ros::Rate loop_rate(rate);
    ROS_DEBUG("sensor board: passed in  fd = %i, this->fd =%i" , fd, this->fd);

    this->fd = fd;
    this->sensor_file = sensor_file;
}

SensorBoardTortugaNode::~SensorBoardTortugaNode() {
    // Close the sensor board
    // close(fd);

}

void SensorBoardTortugaNode::update() {
    //ros::spinOnce();
} 

//This function just checks if the return value from a sensor board call is one of the errors, and prints the error
bool SensorBoardTortugaNode::checkError(int e) {
    switch(e) {
    case SB_IOERROR:
        ROS_DEBUG("IO ERROR in node %s", sensor_file.c_str());
        return true;
    case SB_BADCC:
        ROS_DEBUG("BAD CC ERROR in node %s", sensor_file.c_str());
        return true;
    case SB_HWFAIL:
        ROS_DEBUG("HW FAILURE ERROR in node %s", sensor_file.c_str());
        return true;
    case SB_ERROR:
        ROS_DEBUG("SB ERROR in node %s", sensor_file.c_str());
    }
}
