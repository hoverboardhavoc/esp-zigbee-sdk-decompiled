/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_set_attr_val_post_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ias_zone_cluster_srv_set_attr_val_post_proc
               (zcl_packet_header_t *header,uint16_t attr_id,void *new_value)

{
  uint8_t ep_id;
  uint8_t uVar1;
  ezb_shortaddr_t eVar2;
  ias_zone_srv_zone_ctx_t *piVar3;
  int iVar4;
  undefined2 in_register_0000202e;
  undefined2 uStack_36;
  undefined1 auStack_34 [2];
  nwk_addr_ref_t cie_addr_ref;
  ezb_extaddr_t cie_ieee_addr;
  ezb_address_t dst;
  
  if (CONCAT22(in_register_0000202e,attr_id) == 0x10) {
                    /* WARNING: Load size is inaccurate */
    if (*new_value != 0 || *(int *)((int)new_value + 4) != 0) {
      ep_id = header->dst_ep;
      uVar1 = header->src_ep;
      eVar2 = (header->src_addr).u.short_addr;
      piVar3 = ias_zone_srv_get_zone_ctx(ep_id);
      if (piVar3->cie_ieee_addr_is_set == false) {
        uStack_36 = 0xffff;
        iVar4 = nwk_address_ref_by_short(eVar2,&uStack_36);
        if ((iVar4 == 0) || (iVar4 = nwk_address_update(new_value,eVar2,&uStack_36), iVar4 == 0)) {
          nwk_address_lock_ref(uStack_36);
          memcpy(auStack_34,new_value,8);
          cie_ieee_addr.field_0.u8[4] = '\x03';
          memcpy((void *)((int)&cie_ieee_addr.field_0 + 6),auStack_34,8);
          nwk_get_extended_address();
          iVar4 = aps_bind_table_add(ep_id,0x500,(undefined1 *)((int)&cie_ieee_addr.field_0 + 4),
                                     uVar1);
          if (iVar4 != 0) {
            log_write(1,"ZCL_IAS_ZONE","Failed to add binding to the cie: %d",iVar4);
          }
          piVar3->cie_ieee_addr_is_set = true;
        }
        else {
          log_write(1,"ZCL_IAS_ZONE","Failed to update CIE address: %d",iVar4);
        }
      }
    }
    return;
  }
  return;
}

