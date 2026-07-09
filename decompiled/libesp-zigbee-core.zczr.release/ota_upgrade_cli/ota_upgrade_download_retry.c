/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_download_retry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_download_retry(int param_1)

{
  int iVar1;
  undefined1 auStack_38 [44];
  
  memset(auStack_38,0,0x28);
  if (param_1 == 0) {
    __assert_func(0,0,0,0);
  }
  iVar1 = param_1 + 0x4c;
  if (*(byte *)(param_1 + 0x38) < *(byte *)(param_1 + 0x31)) {
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) + 1;
    zcl_packet_move(auStack_38,iVar1);
    ota_upgrade_packet_send(auStack_38);
  }
  else {
    zcl_packet_setup_response(auStack_38,iVar1,*(undefined1 *)(param_1 + 0x6c));
    zcl_message_ota_upgrade_downloading_progress(auStack_38,6,param_1);
    zcl_packet_free(iVar1);
    *(undefined1 *)(param_1 + 0x38) = 0;
  }
  log_write(2,"ZCL_OTA_UPGRADE_CLI","Downloading retry [%d/%d], timeout: %lu ms",
            *(undefined1 *)(param_1 + 0x38),*(undefined1 *)(param_1 + 0x31),
            *(undefined4 *)(param_1 + 0x34));
  return;
}

