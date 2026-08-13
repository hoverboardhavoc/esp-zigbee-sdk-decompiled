/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_upgrade_end_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_cluster_cli_upgrade_end_rsp_handler(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  iStack_28 = 0;
  if (param_1 == 0) {
    iVar1 = 1;
  }
  else if (param_2 == 0) {
    iVar1 = 1;
  }
  else {
    iVar2 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
    if (iVar2 == 0) {
      iVar1 = 0xfe;
    }
    else if (**(char **)(iVar2 + 0x18) == '\x02') {
      uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 2);
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&iStack_28);
      if (uVar4 < auStack_22[0]) {
        iVar1 = 0x80;
      }
      else {
        ota_upgrade_download_stop_retry(iVar2,6);
        iVar1 = ota_upgrade_handle_upgrade_end(iVar2,&uStack_34);
        if (iVar1 == 0) {
          if (iStack_28 == -1) {
            **(undefined1 **)(iVar2 + 0x18) = 3;
          }
          else {
            iVar1 = zcl_message_ota_upgrade_downloading_progress(param_1,4,&uStack_34);
            if (iVar1 == 0x96) {
              ota_upgrade_set_upgrade_status_normal(iVar2);
              iVar1 = ota_upgrade_setup_upgrade_end_request(param_2,iVar2,param_1,0x96);
            }
            else if (iVar1 == 0x99) {
              **(undefined1 **)(iVar2 + 0x18) = 5;
              iVar1 = ota_upgrade_setup_upgrade_end_request(param_2,iVar2,param_1,0x99);
            }
            else {
              if (iVar1 != 0) {
                ota_upgrade_set_upgrade_status_normal(iVar2);
                iVar1 = 0xfe;
                goto _L0;
              }
              **(undefined1 **)(iVar2 + 0x18) = 4;
              zcl_message_ota_upgrade_downloading_progress(param_1,5,&uStack_34);
              ota_upgrade_set_upgrade_status_normal(iVar2);
              iVar1 = 0;
            }
          }
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      iVar1 = 0xfe;
    }
  }
_L0:
  uVar3 = zcl_packet_setup_default_response(param_2,param_1,iVar1);
  return uVar3;
}

