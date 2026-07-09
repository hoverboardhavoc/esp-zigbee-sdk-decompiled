/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  uint uVar3;
  undefined4 uVar4;
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
    iVar2 = 1;
  }
  else if (param_2 == 0) {
    iVar2 = 1;
  }
  else {
    iVar1 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
    iVar2 = ota_upgrade_download_stop_timer();
    if (iVar2 == 0) {
      iVar2 = 0xfe;
    }
    else if (**(char **)(iVar1 + 0x18) == '\x02') {
      uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
      af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 2);
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
      af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&iStack_28);
      if (uVar3 < auStack_22[0]) {
        iVar2 = 0x80;
      }
      else {
        iVar2 = ota_upgrade_handle_upgrade_end(iVar1,&uStack_34);
        if (iVar2 == 0) {
          if (iStack_28 == -1) {
            **(undefined1 **)(iVar1 + 0x18) = 3;
          }
          else {
            iVar2 = zcl_message_ota_upgrade_downloading_progress(param_1,4,&uStack_34);
            if (iVar2 == 0x96) {
              ota_upgrade_set_upgrade_status_normal(iVar1);
              iVar2 = ota_upgrade_setup_upgrade_end_request(param_2,iVar1,param_1,0x96);
            }
            else if (iVar2 == 0x99) {
              **(undefined1 **)(iVar1 + 0x18) = 5;
              iVar2 = ota_upgrade_setup_upgrade_end_request(param_2,iVar1,param_1,0x99);
            }
            else {
              if (iVar2 != 0) {
                ota_upgrade_set_upgrade_status_normal(iVar1);
                iVar2 = 0xfe;
                goto _L0;
              }
              **(undefined1 **)(iVar1 + 0x18) = 4;
              zcl_message_ota_upgrade_downloading_progress(param_1,5,&uStack_34);
              ota_upgrade_set_upgrade_status_normal(iVar1);
              iVar2 = 0;
            }
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      iVar2 = 0xfe;
    }
  }
_L0:
  uVar4 = zcl_packet_setup_default_response(param_2,param_1,iVar2);
  return uVar4;
}

