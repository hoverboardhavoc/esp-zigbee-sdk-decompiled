/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_timer_ctx_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void identify_timer_ctx_get(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = identify_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xaa,
                  "identify_timer_ctx_get","timer_ctx_attr_desc");
  }
  else if (*(int *)(iVar1 + 8) != 0) {
    return;
  }
  pcVar2 = "identify_timer_ctx_get";
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xac
                        ,"identify_timer_ctx_get","timer_ctx");
  if (iVar1 == 0xeff0) {
    ezb_zcl_set_attr_value(3,1,0xeff0,0x131b,pcVar2,0);
  }
  else {
    ezb_zcl_set_attr_value(3,1,0,0);
  }
  return;
}

