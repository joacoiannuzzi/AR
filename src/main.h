//
// Created by joaco on 28/10/20.
//

#ifndef OPENVSLAM_TEST_MAIN_H
#define OPENVSLAM_TEST_MAIN_H

#include <openvslam/config.h>

void mono_tracking(const std::shared_ptr<openvslam::config> &cfg,
                   const std::string &vocab_file_path, const std::string &video_file_path,
                   const std::string &mask_img_path,
                   const unsigned int frame_skip, const bool no_sleep, const bool auto_term,
                   const bool eval_log, const std::string &map_db_path);

void camera_tracking(const std::shared_ptr<openvslam::config>& cfg,
                     const std::string& vocab_file_path, const unsigned int cam_num, const std::string& mask_img_path,
                     const float scale, const std::string& map_db_path);


int main();


#endif //OPENVSLAM_TEST_MAIN_H
