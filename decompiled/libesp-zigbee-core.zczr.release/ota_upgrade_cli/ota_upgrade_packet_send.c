/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ota_upgrade_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ota_upgrade_packet_send(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) goto _L15;
  do {
    param_1 = __assert_func(0,0,0,0);
_L15:
    iVar1 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x14));
  } while (iVar1 == 0);
  zcl_packet_clone(iVar1 + 0x4c,param_1);
  zcl_packet_send(param_1,0);
  milli_timer_stop();
  milli_timer_start(iVar1 + 0x3c,*(undefined4 *)(iVar1 + 0x34));
  return;
}

