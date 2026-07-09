/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_srv_cvc_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

undefined4 color_control_srv_cvc_ctx_init(void)

{
  int iVar1;
  void *__s;
  
  iVar1 = color_control_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x15b
                  ,"color_control_srv_cvc_ctx_init","cvc_ctx_desc");
  }
  else {
    __s = calloc(2,0x40);
    *(void **)(iVar1 + 8) = __s;
    if (__s != (void *)0x0) {
      memset(__s,0,0x80);
      return 0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x15e,
                "color_control_srv_cvc_ctx_init","cvc_ctx_desc->data_p");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

