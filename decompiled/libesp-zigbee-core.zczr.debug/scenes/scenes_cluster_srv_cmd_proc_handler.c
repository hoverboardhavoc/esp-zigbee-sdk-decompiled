/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scenes_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined1 auStack_38 [4];
  zcl_packet_t rsp;
  
  auStack_38 = (undefined1  [4])0x0;
  rsp.header.src_addr._0_4_ = 0;
  rsp.header.src_addr.u._2_4_ = 0;
  rsp.header._8_4_ = 0;
  rsp.header.dst_addr.u._0_2_ = 0;
  rsp.header.dst_addr.u._2_2_ = 0;
  rsp.header.dst_addr.u._4_4_ = 0;
  rsp.header.src_ep = '\0';
  rsp.header.dst_ep = '\0';
  rsp.header.cluster_id = 0;
  rsp.header.profile_id = 0;
  rsp.header.fc = '\0';
  rsp.header._27_1_ = 0;
  rsp.header.manuf_code = 0;
  rsp.header.tsn = '\0';
  rsp.header.rssi = '\0';
  rsp.header.cmd_id = '\0';
  rsp.header._33_1_ = 0;
  rsp._34_2_ = 0;
  if (arg == (void *)0x0) {
    iVar2 = 1;
  }
  else if ((*(byte *)((int)arg + 0x1a) >> 3 & 1) == 0) {
    iVar2 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar2 == 0) {
      bVar1 = *(byte *)((int)arg + 0x20);
      if (bVar1 == 5) {
        eVar3 = scenes_cluster_recall_scene_req_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_06,eVar3);
      }
      else if (bVar1 < 6) {
        if (bVar1 == 2) {
          eVar3 = scenes_cluster_remove_scene_req_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_04,eVar3);
        }
        else if (bVar1 < 3) {
          if (bVar1 == 0) {
            eVar3 = scenes_cluster_add_scene_req_handler
                              ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
            iVar2 = CONCAT31(extraout_var_03,eVar3);
          }
          else {
            if (bVar1 != 1) {
              iVar2 = 0x81;
              goto _L0;
            }
            eVar3 = scenes_cluster_view_scene_req_handler
                              ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
            iVar2 = CONCAT31(extraout_var,eVar3);
          }
        }
        else if (bVar1 == 3) {
          eVar3 = scenes_cluster_remove_all_scenes_req_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_05,eVar3);
        }
        else {
          if (bVar1 != 4) {
            iVar2 = 0x81;
            goto _L0;
          }
          eVar3 = scenes_cluster_store_scene_req_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_00,eVar3);
        }
      }
      else if (bVar1 == 0x41) {
        eVar3 = scenes_cluster_enhanced_view_scene_req_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_08,eVar3);
      }
      else if (bVar1 < 0x42) {
        if (bVar1 == 6) {
          eVar3 = scenes_cluster_get_scene_membership_req_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_07,eVar3);
        }
        else {
          if (bVar1 != 0x40) {
            iVar2 = 0x81;
            goto _L0;
          }
          eVar3 = scenes_cluster_enhanced_add_scene_req_handler
                            ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
          iVar2 = CONCAT31(extraout_var_01,eVar3);
        }
      }
      else {
        if (bVar1 != 0x42) {
          iVar2 = 0x81;
          goto _L0;
        }
        eVar3 = scenes_cluster_copy_scene_req_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)auStack_38);
        iVar2 = CONCAT31(extraout_var_02,eVar3);
      }
      if (iVar2 == 0) {
        zcl_packet_send(auStack_38,0);
      }
      else {
        zcl_packet_free(auStack_38);
      }
    }
  }
  else {
    iVar2 = 1;
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

