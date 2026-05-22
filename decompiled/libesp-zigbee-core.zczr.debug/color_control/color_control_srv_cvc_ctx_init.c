/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_srv_cvc_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t color_control_srv_cvc_ctx_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  void *__s;
  
  pzVar1 = color_control_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x15b
                  ,"color_control_srv_cvc_ctx_init","cvc_ctx_desc");
  }
  else {
    __s = calloc(2,0x40);
    pzVar1->data_p = __s;
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

