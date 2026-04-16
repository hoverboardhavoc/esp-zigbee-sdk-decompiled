/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void on_off_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  zcl_attr_desc_t *pzVar1;
  undefined2 in_register_0000202e;
  
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
  if ((((CONCAT22(in_register_0000202e,attr_id) == 0) &&
       (pzVar1 = on_off_srv_get_attr_desc(endpoint,0x4000), pzVar1 != (zcl_attr_desc_t *)0x0)) &&
      (*pzVar1->data_p == '\0')) && ((new_value != (void *)0x0 && (*new_value != '\0')))) {
    *(char *)pzVar1->data_p = '\x01';
  }
  return;
}

