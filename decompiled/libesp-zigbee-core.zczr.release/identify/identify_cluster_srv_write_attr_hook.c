/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void identify_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  short sVar1;
  zcl_attr_desc_t *pzVar2;
  undefined2 in_register_0000202e;
  
                    /* WARNING: Load size is inaccurate */
  sVar1 = *new_value;
  pzVar2 = identify_srv_get_attr_desc(endpoint,attr_id);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) goto _L0;
  do {
    pzVar2 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
  } while (pzVar2->data_p == (void *)0x0);
  if (CONCAT22(in_register_0000202e,attr_id) == 0) {
    if (sVar1 != 0) {
      milli_timer_start(1000);
      return;
    }
    milli_timer_stop((int)pzVar2->data_p + 4);
    return;
  }
  return;
}

