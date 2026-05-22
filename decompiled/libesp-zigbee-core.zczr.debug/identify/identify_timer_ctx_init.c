/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_timer_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_err_t identify_timer_ctx_init(uint8_t ep_id)

{
  uint8_t ep_id_00;
  zcl_attr_desc_t *pzVar1;
  uint8_t *puVar2;
  ezb_err_t eVar3;
  
  pzVar1 = identify_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x8d,
                  "identify_timer_ctx_init","timer_ctx_attr_desc");
  }
  else {
    puVar2 = (uint8_t *)calloc(1,0x14);
    pzVar1->data_p = puVar2;
    if (puVar2 != (uint8_t *)0x0) {
      *puVar2 = ep_id;
      milli_timer_init(puVar2 + 4,identify_timer_handler,puVar2);
      return 0;
    }
  }
  ep_id_00 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",
                           0x8f,"identify_timer_ctx_init","timer_ctx_attr_desc->data_p");
  pzVar1 = identify_srv_get_attr_desc(ep_id_00,0xeff0);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    milli_timer_stop((int)pzVar1->data_p + 4);
    eVar3 = mm_free(pzVar1->data_p);
    pzVar1->data_p = (void *)0x0;
    return eVar3;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0xa9,
                "identify_timer_ctx_deinit","timer_ctx_attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

