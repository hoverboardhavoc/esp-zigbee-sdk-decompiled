/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_setup_query_next_image_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_setup_query_next_image_request(int param_1,int param_2,int param_3)

{
  int iVar1;
  int unaff_s2;
  uint uStack_14;
  
  if (((param_1 == 0) || (param_3 == 0)) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x22c,"ota_upgrade_setup_query_next_image_request",
                  "sent_packet && recv_packet && context");
  }
  else {
    unaff_s2 = zcl_packet_setup_response_with_extension(param_3,1,0);
    if (unaff_s2 != 0) {
      return unaff_s2;
    }
  }
  uStack_14 = uStack_14 & 0xffffff00;
  iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),1,&uStack_14);
  if (iVar1 == 0) {
    uStack_14._0_2_ = **(undefined2 **)(param_2 + 0x1c);
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),2,&uStack_14);
    if (iVar1 == 0) {
      uStack_14 = CONCAT22(uStack_14._2_2_,**(undefined2 **)(param_2 + 0x20));
      iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),2,&uStack_14);
      if (iVar1 == 0) {
        if (*(uint **)(param_2 + 8) == (uint *)0x0) {
          uStack_14 = 0xffffffff;
        }
        else {
          uStack_14 = **(uint **)(param_2 + 8);
        }
        iVar1 = zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),4,&uStack_14);
        if (iVar1 != 0) {
          unaff_s2 = 0x89;
        }
      }
      else {
        unaff_s2 = 0x89;
      }
    }
    else {
      unaff_s2 = 0x89;
    }
  }
  else {
    unaff_s2 = 0x89;
  }
  return unaff_s2;
}

