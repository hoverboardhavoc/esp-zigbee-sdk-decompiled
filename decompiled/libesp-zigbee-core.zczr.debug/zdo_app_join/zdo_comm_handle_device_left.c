/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_handle_device_left
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_handle_device_left(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xcc0) == '\0') {
    zdo_comm_signal_device_left(param_1);
  }
  else {
    iVar1 = core_globals_get();
    uVar2 = zdo_comm_op_to_str(*(undefined1 *)(iVar1 + 0xcc0));
    log_write(1,"zdo_app_join.c",0x10998,uVar2);
  }
  return;
}

