/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_cluster_cli_image_block_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int ota_upgrade_cluster_cli_image_block_rsp_handler(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint __size;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_36 [2];
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_28;
  ushort auStack_22 [5];
  
  auStack_22[0] = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
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
    else if (**(char **)(iVar1 + 0x18) == '\x01') {
      uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_3c);
      if ((uStack_3c & 0xff) == 0) {
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&stack0xffffffc8);
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,auStack_36);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
        af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
        __size = uStack_2c & 0xff;
        pvStack_28 = calloc(1,__size);
        if ((pvStack_28 == (void *)0x0) && (__size != 0)) {
          iVar2 = 0x89;
          goto _L0;
        }
        af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,__size,pvStack_28);
      }
      else if ((uStack_3c & 0xff) == 0x97) {
        af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&stack0xffffffc8);
        af_read_le32(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_30);
      }
      if (uVar3 < auStack_22[0]) {
        iVar2 = 0x80;
      }
      else if ((uStack_3c & 0xff) == 0) {
        iVar2 = ota_upgrade_handle_image_block_with_success(iVar1,&uStack_3c);
        if (iVar2 == 0) {
          iVar2 = ota_upgrade_setup_upgrade_end_request(param_2,iVar1,param_1,0);
        }
        else {
          if (iVar2 != 0x99) {
            iVar2 = 0xfe;
            goto _L0;
          }
          iVar2 = ota_upgrade_setup_image_block_request(param_2,iVar1,param_1);
        }
        if (iVar2 == 0) {
          zcl_message_ota_upgrade_downloading_progress(param_1,1,&uStack_3c);
          if (**(char **)(iVar1 + 0x18) == '\x02') {
            zcl_message_ota_upgrade_downloading_progress(param_1,3,&uStack_3c);
          }
        }
      }
      else if ((uStack_3c & 0xff) == 0x97) {
        iVar2 = 0x85;
      }
      else {
        iVar2 = 0x95;
      }
    }
    else {
      iVar2 = 0xfe;
    }
  }
_L0:
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  if (iVar2 != 0) {
    iVar2 = zcl_packet_setup_default_response(param_2,param_1,iVar2);
  }
  return iVar2;
}

