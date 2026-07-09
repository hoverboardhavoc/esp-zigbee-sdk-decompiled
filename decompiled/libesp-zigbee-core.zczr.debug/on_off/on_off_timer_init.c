/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_timer_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 on_off_timer_init(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar1 = on_off_srv_get_attr_desc(0x4001);
  iVar2 = on_off_srv_get_attr_desc(param_1,0x4002);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    iVar1 = on_off_srv_get_attr_desc(param_1,0xeff0);
    if (iVar1 == 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x28b,
                    "on_off_timer_init","on_off_timer_attr_desc");
    }
    else {
      puVar3 = (undefined1 *)calloc(1,0x14);
      *(undefined1 **)(iVar1 + 8) = puVar3;
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = (char)param_1;
        milli_timer_init(puVar3 + 4,on_off_timer_handler,puVar3);
        return 0;
      }
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x28d,
                  "on_off_timer_init","on_off_timer_attr_desc->data_p");
    iVar1 = on_off_srv_get_attr_desc(0xeff0);
    if (iVar1 != 0) {
      milli_timer_stop(*(int *)(iVar1 + 8) + 4);
    }
    return 0;
  }
  return 0;
}

