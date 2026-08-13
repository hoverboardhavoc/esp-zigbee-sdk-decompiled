/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_image_notify_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_cluster_cli_image_notify_req_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int unaff_s2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  local_30 = 0xffff0000;
  uStack_2c = 0xffff;
  uStack_28 = 0xffffffff;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x286,"ota_upgrade_cluster_cli_image_notify_req_handler","packet && rsp");
  }
  else {
    unaff_s2 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
    if (**(char **)(unaff_s2 + 0x18) != '\0') {
      iVar2 = 0x95;
      goto _L0;
    }
  }
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&local_30);
  if ((local_30 & 0xff) < 4) {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&local_30 + 1);
    if ((local_30 & 0xff) != 0) {
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&local_30 + 2);
    }
    if (1 < (local_30 & 0xff)) {
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
    }
    if (2 < (local_30 & 0xff)) {
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_28);
    }
    if (uVar1 < auStack_22[0]) {
      iVar2 = 0x80;
    }
    else {
      iVar2 = ota_upgrade_handle_image_notify(unaff_s2,*(undefined2 *)(param_1 + 0xc),&local_30);
      if (iVar2 == 0) {
        ota_upgrade_setup_query_next_image_request(param_2,unaff_s2,param_1);
        return;
      }
    }
  }
  else {
    iVar2 = 0x85;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar2);
  return;
}

