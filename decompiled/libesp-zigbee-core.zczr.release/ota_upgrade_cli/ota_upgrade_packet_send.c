/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_packet_send(int param_1)

{
  int iVar1;
  code *pcStack_18;
  int iStack_14;
  
  if (param_1 != 0) goto _L15;
  do {
    param_1 = __assert_func(0,0,0,0);
_L15:
    pcStack_18 = (code *)0x0;
    iStack_14 = 0;
    iVar1 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x14));
  } while (iVar1 == 0);
  pcStack_18 = ota_upgrade_packet_confirm_handler;
  iStack_14 = iVar1;
  zcl_packet_clone(iVar1 + 0x4c,param_1);
  zcl_packet_send(param_1,&pcStack_18);
  return;
}

