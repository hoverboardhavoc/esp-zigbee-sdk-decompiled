/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_timer_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 identify_timer_ctx_init(undefined1 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  iVar1 = identify_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x9a,
                  "identify_timer_ctx_init","timer_ctx_attr_desc");
  }
  else {
    puVar2 = (undefined1 *)calloc(1,0x14);
    *(undefined1 **)(iVar1 + 8) = puVar2;
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = param_1;
      milli_timer_init(puVar2 + 4,identify_timer_handler,puVar2);
      return 0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x9c,
                "identify_timer_ctx_init","timer_ctx_attr_desc->data_p");
  iVar1 = identify_srv_get_attr_desc(0xeff0);
  if (iVar1 != 0) {
    milli_timer_stop(*(int *)(iVar1 + 8) + 4);
    uVar3 = mm_free(*(undefined4 *)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 8) = 0;
    return uVar3;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xb6,
                "identify_timer_ctx_deinit","timer_ctx_attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

