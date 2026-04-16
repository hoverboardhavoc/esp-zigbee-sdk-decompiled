/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_create_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_attr_desc_t *
zcl_create_attr_desc(uint16_t id,uint8_t type,uint8_t access,uint16_t manuf_code,void *data_p)

{
  size_t __size;
  zcl_attr_desc_t *pzVar1;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002036;
  byte bVar2;
  void *pvVar3;
  
  __size = zcl_get_attr_value_size(CONCAT31(in_register_0000202d,type),data_p);
  if (__size == 0xffff) {
    pzVar1 = (zcl_attr_desc_t *)0x0;
  }
  else {
    pzVar1 = (zcl_attr_desc_t *)calloc(1,0x10);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      pzVar1->id = id;
      if (__size == 0) {
        pvVar3 = (void *)0x0;
      }
      else {
        pvVar3 = calloc(1,__size);
      }
      pzVar1->data_p = pvVar3;
      pzVar1->manuf_code = manuf_code;
      pzVar1->type = type;
      if (CONCAT22(in_register_00002036,manuf_code) == 0) {
        bVar2 = access & 0xdf;
      }
      else {
        bVar2 = access | 0x20;
      }
      pzVar1->access = bVar2;
      pzVar1->next = (zcl_attr_desc_s *)0x0;
      if ((__size == 0) || (pvVar3 != (void *)0x0)) {
        zcl_write_attr_value(pvVar3,data_p,CONCAT31(in_register_0000202d,type));
      }
      else {
        mm_free(pzVar1);
        pzVar1 = (zcl_attr_desc_t *)0x0;
      }
    }
  }
  return pzVar1;
}

