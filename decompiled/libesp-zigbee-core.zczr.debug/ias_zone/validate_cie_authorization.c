/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> validate_cie_authorization
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: cie_ieee_addr */
/* WARNING: Unknown calling convention */

_Bool validate_cie_authorization(uint8_t ep_id,uint16_t short_addr)

{
  int iVar1;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  undefined2 in_register_0000202e;
  int in_a4;
  int unaff_s2;
  ezb_extaddr_t cie_addr_val;
  ezb_extaddr_t cie_ieee_addr;
  
  cie_addr_val.field_0.u64._4_4_ = 0;
  cie_addr_val.field_0.u64._0_4_ = 0;
  pzVar2 = ias_zone_srv_get_attr_desc(ep_id,0x10);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x78,
                  "validate_cie_authorization","attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    iVar1 = *pzVar2->data_p;
    unaff_s2 = *(int *)((int)pzVar2->data_p + 4);
    cie_addr_val.field_0.u64._0_4_ = unaff_s2;
    iVar3 = nwk_address_extended_by_short
                      (CONCAT22(in_register_0000202e,short_addr),
                       (undefined1 *)((int)&cie_addr_val.field_0 + 4));
    if (iVar3 != 0) {
      return false;
    }
    in_a4 = 0;
    if (cie_addr_val.field_0.u64._4_4_ != iVar1) {
      return false;
    }
  }
  if (in_a4 != unaff_s2) {
    return false;
  }
  return true;
}

