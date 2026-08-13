/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_query_next_image_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_cluster_cli_query_next_image_rsp_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_1 == 0) {
    iVar3 = 1;
  }
  else if (param_2 == 0) {
    iVar3 = 1;
  }
  else {
    iVar1 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
    if (iVar1 == 0) {
      iVar3 = 0xfe;
    }
    else if (**(char **)(iVar1 + 0x18) == '\0') {
      uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
      if ((uStack_34 & 0xff) == 0) {
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 2);
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_28);
      }
      if (uVar2 < auStack_22[0]) {
        iVar3 = 0x80;
      }
      else {
        ota_upgrade_download_stop_retry(iVar1,1);
        iVar3 = zcl_message_ota_upgrade_query_next_image(param_1,&uStack_34);
        if ((iVar3 == 0) && (iVar3 = ota_upgrade_handle_next_image(iVar1,&uStack_34,0), iVar3 == 0))
        {
          zcl_message_ota_upgrade_downloading_progress(param_1,0,&uStack_34);
          ota_upgrade_setup_image_block_request(param_2,iVar1,param_1);
          return;
        }
      }
    }
    else {
      iVar3 = 0x95;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,iVar3);
  return;
}

