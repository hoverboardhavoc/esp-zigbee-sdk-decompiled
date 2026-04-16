/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> time_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t time_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  zcl_attr_desc_t *pzVar3;
  byte *in_a5;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  pzVar3 = time_server_get_attr_desc(endpoint,1);
  if ((pzVar3 == (zcl_attr_desc_t *)0x0) || (in_a5 = (byte *)pzVar3->data_p, in_a5 == (byte *)0x0))
  {
    __assert_func(0,0,0,0);
  }
  if (uVar2 == 1) {
                    /* WARNING: Load size is inaccurate */
    return -(((*value ^ *in_a5) & 5) != 0) & 0x88;
  }
  if (uVar2 < 2) {
    if ((*in_a5 & 1) != 0) {
      return 0x88;
    }
  }
  else {
    if (3 < (uVar2 - 2 & 0xffff)) {
      return '\0';
    }
    if ((*in_a5 & 4) != 0) {
      return 0x88;
    }
  }
                    /* WARNING: Load size is inaccurate */
  eVar1 = 0x87;
  if (*value != -1) {
    eVar1 = '\0';
  }
  return eVar1;
}

