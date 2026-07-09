/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_download_retry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_download_retry(int param_1)

{
  int iVar1;
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
    iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                          ,0x182,"ota_upgrade_download_retry","context");
  }
  else {
    iVar1 = param_1;
    if (*(byte *)(param_1 + 0x38) < *(byte *)(param_1 + 0x31)) {
      *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) + 1;
      zcl_packet_move(&uStack_38,param_1 + 0x4c);
      ota_upgrade_packet_send(&uStack_38);
      goto _L0;
    }
  }
  zcl_packet_setup_response(&uStack_38,iVar1 + 0x4c,*(undefined1 *)(iVar1 + 0x6c));
  zcl_message_ota_upgrade_downloading_progress(&uStack_38,6,param_1);
  zcl_packet_free(iVar1 + 0x4c);
  *(undefined1 *)(param_1 + 0x38) = 0;
_L0:
  log_write(2,"ZCL_OTA_UPGRADE_CLI","Downloading retry [%d/%d], timeout: %lu ms",
            *(undefined1 *)(param_1 + 0x38),*(undefined1 *)(param_1 + 0x31),
            *(undefined4 *)(param_1 + 0x34));
  return;
}

