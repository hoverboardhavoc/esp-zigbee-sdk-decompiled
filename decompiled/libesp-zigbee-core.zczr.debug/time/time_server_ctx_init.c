/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_server_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 time_server_ctx_init(undefined1 param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  iVar1 = time_server_get_manufacturer_attr_desc(0xeffe);
  if (iVar1 == 0) {
    uVar3 = 5;
  }
  else {
    pvVar2 = calloc(1,0x28);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 1;
    }
    else {
      *(void **)(iVar1 + 8) = pvVar2;
      milli_timer_init((int)pvVar2 + 0xc,zcl_time_server_sync_finished,pvVar2);
      *(undefined1 *)((int)pvVar2 + 0x25) = param_1;
      uVar3 = 0;
    }
  }
  return uVar3;
}

