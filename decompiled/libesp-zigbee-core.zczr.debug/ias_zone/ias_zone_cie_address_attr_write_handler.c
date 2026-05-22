/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cie_address_attr_write_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ias_zone_cie_address_attr_write_handler
               (uint8_t zone_ep,uint8_t cie_ep,uint16_t short_addr,void *new_value)

{
  undefined3 in_register_00002029;
  ias_zone_srv_zone_ctx_t *piVar1;
  int iVar2;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002032;
  undefined2 uStack_36;
  undefined2 uStack_34;
  nwk_addr_ref_t cie_addr_ref;
  ezb_extaddr_t cie_ieee_addr;
  ezb_address_t dst;
  
                    /* WARNING: Load size is inaccurate */
  if ((*new_value != 0 || *(int *)((int)new_value + 4) != 0) &&
     (piVar1 = ias_zone_srv_get_zone_ctx(zone_ep), piVar1->cie_ieee_addr_is_set == false)) {
    uStack_36 = 0xffff;
    iVar2 = nwk_address_ref_by_short(CONCAT22(in_register_00002032,short_addr),&uStack_36);
    if ((iVar2 == 0) ||
       (iVar2 = nwk_address_update(new_value,CONCAT22(in_register_00002032,short_addr),&uStack_36),
       iVar2 == 0)) {
      nwk_address_lock_ref(uStack_36);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      cie_ieee_addr.field_0.u64._0_4_ = *(undefined4 *)((int)new_value + 4);
      cie_ieee_addr.field_0.u8[4] = '\x03';
      uStack_34 = (undefined2)*new_value;
      cie_ieee_addr.field_0.u64._6_2_ = uStack_34;
      _uStack_34 = *new_value;
      nwk_get_extended_address();
      iVar2 = aps_bind_table_add(CONCAT31(in_register_00002029,zone_ep),0x500,
                                 (undefined1 *)((int)&cie_ieee_addr.field_0 + 4),
                                 CONCAT31(in_register_0000202d,cie_ep));
      if (iVar2 != 0) {
        log_write(1,"ZCL_IAS_ZONE","Failed to add binding to the cie: %d",iVar2);
      }
      piVar1->cie_ieee_addr_is_set = true;
    }
    else {
      log_write(1,"ZCL_IAS_ZONE",0x10100,iVar2);
    }
  }
  return;
}

