/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_cluster_cli_cmd_proc_handler(int param_1)

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
  uint uStack_18;
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
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(&uStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 5) {
    iVar2 = ota_upgrade_cluster_cli_image_block_rsp_handler(param_1,&uStack_38);
    goto _L0;
  }
  if (bVar1 < 6) {
    if (bVar1 == 0) {
      iVar2 = ota_upgrade_cluster_cli_image_notify_req_handler(param_1,&uStack_38);
      goto _L0;
    }
    if (bVar1 == 2) {
      iVar2 = ota_upgrade_cluster_cli_query_next_image_rsp_handler(param_1,&uStack_38);
      goto _L0;
    }
  }
  else if (bVar1 == 7) {
    iVar2 = ota_upgrade_cluster_cli_upgrade_end_rsp_handler(param_1,&uStack_38);
    goto _L0;
  }
  iVar2 = zcl_packet_setup_default_response(&uStack_38,param_1,0x81);
_L0:
  if (iVar2 == 0) {
    if ((uStack_18 & 0xff) == 0xb) {
      zcl_packet_send(&uStack_38,0);
    }
    else {
      ota_upgrade_packet_send(&uStack_38);
    }
  }
  else {
    zcl_packet_free(&uStack_38);
  }
  return iVar2;
}

