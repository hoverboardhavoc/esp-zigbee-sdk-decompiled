/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int scenes_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar2 = 1;
  }
  else if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) == 0) {
    iVar2 = zcl_packet_init(&uStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
    if (iVar2 == 0) {
      bVar1 = *(byte *)(param_1 + 0x20);
      if (bVar1 == 5) {
        iVar2 = scenes_cluster_recall_scene_req_handler(param_1,&uStack_38);
      }
      else if (bVar1 < 6) {
        if (bVar1 == 2) {
          iVar2 = scenes_cluster_remove_scene_req_handler(param_1,&uStack_38);
        }
        else if (bVar1 < 3) {
          if (bVar1 == 0) {
            iVar2 = scenes_cluster_add_scene_req_handler(param_1,&uStack_38);
          }
          else {
            if (bVar1 != 1) {
              return 0x81;
            }
            iVar2 = scenes_cluster_view_scene_req_handler(param_1,&uStack_38);
          }
        }
        else if (bVar1 == 3) {
          iVar2 = scenes_cluster_remove_all_scenes_req_handler(param_1,&uStack_38);
        }
        else {
          if (bVar1 != 4) {
            return 0x81;
          }
          iVar2 = scenes_cluster_store_scene_req_handler(param_1,&uStack_38);
        }
      }
      else if (bVar1 == 0x41) {
        iVar2 = scenes_cluster_enhanced_view_scene_req_handler(param_1,&uStack_38);
      }
      else if (bVar1 < 0x42) {
        if (bVar1 == 6) {
          iVar2 = scenes_cluster_get_scene_membership_req_handler(param_1,&uStack_38);
        }
        else {
          if (bVar1 != 0x40) {
            return 0x81;
          }
          iVar2 = scenes_cluster_enhanced_add_scene_req_handler(param_1,&uStack_38);
        }
      }
      else {
        if (bVar1 != 0x42) {
          return 0x81;
        }
        iVar2 = scenes_cluster_copy_scene_req_handler(param_1,&uStack_38);
      }
      if (iVar2 == 0) {
        zcl_packet_send(&uStack_38,0);
      }
      else {
        zcl_packet_free(&uStack_38);
      }
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}

