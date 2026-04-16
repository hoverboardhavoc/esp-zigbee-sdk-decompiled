/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_annce_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_device_annce_handler(zdo_packet_t *packet)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int extraout_a0;
  int extraout_a0_00;
  int extraout_a0_01;
  uint16_t *offset_00;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 ieee_addr;
  short sStack_2c;
  ushort uStack_2a;
  ezb_shortaddr_t existing_nwk_addr;
  nwk_addr_ref_t addr_ref;
  ezb_extaddr_t nbr_ieee_addr;
  zdp_device_annce_t annce;
  uint16_t offset;
  
  annce.nwk_addr = 0;
  nbr_ieee_addr.field_0.u64._4_4_ = 0;
  annce.ieee_addr.field_0.u64._0_4_ = 0;
  annce.ieee_addr.field_0.u64._4_4_ = 0;
  if (packet == (zdo_packet_t *)0x0) {
    return 0xfe;
  }
  if (packet->payload == (zdo_packet_payload_t *)0x0) {
    return 0xfe;
  }
  uVar1 = zmsg_get_length();
  offset_00 = &annce.nwk_addr;
  af_read_le16(packet->payload,offset_00,(uint16_t *)(annce.ieee_addr.field_0.u8 + 4));
  af_read_bytes(packet->payload,offset_00,8,nbr_ieee_addr.field_0.u8 + 4);
  af_read_le8(packet->payload,offset_00,annce.ieee_addr.field_0.u8 + 6);
  if (uVar1 < annce.nwk_addr) {
    return 0xfe;
  }
  piVar2 = (int *)nwk_get_extended_address();
  if ((nbr_ieee_addr.field_0.u64._4_4_ == *piVar2) &&
     (annce.ieee_addr.field_0.u64._0_4_ == piVar2[1])) {
    return 0xfe;
  }
  iVar3 = nwk_is_device_zczr();
  if (iVar3 != 0) {
    sStack_2c = -1;
    iVar4 = nwk_address_ref_by_extended((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4),&uStack_2a);
    if ((((iVar4 == 0) && (iVar4 = nwk_address_short_by_ref(uStack_2a,&sStack_2c), iVar4 == 0)) &&
        (sStack_2c != -1)) && (sStack_2c != annce.ieee_addr.field_0.u64._4_2_)) {
_L0:
      if (iVar3 == 0) goto _L0;
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      do {
        iVar4 = nwk_neighbor_table_next(iVar4);
        if (iVar4 == 0) {
          iVar3 = 0;
          goto _L0;
        }
        nwk_neighbor_get_extaddr(iVar4,&existing_nwk_addr);
      } while (((nbr_ieee_addr.field_0.u64._4_4_ != _existing_nwk_addr) ||
               (annce.ieee_addr.field_0.u64._0_4_ != nbr_ieee_addr.field_0.u64._0_4_)) ||
              (uVar1 = nwk_neighbor_get_shortaddr(iVar4),
              (annce.ieee_addr.field_0.u64._4_4_ & 0xffff) == uVar1));
    }
    if ((iVar4 != 0) && ((*(uint *)(iVar4 + 0xc) & 0x3c0) == 0x180)) {
      *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xfffffc3f | 0x1c0;
    }
    if (iVar3 != 0) {
      return 0xfe;
    }
  }
_L0:
  annce.capability = '\0';
  annce._11_1_ = 0;
  ieee_addr.u64 =
       nwk_address_update((undefined1 *)((int)&nbr_ieee_addr.field_0 + 4),
                          annce.ieee_addr.field_0.u64._4_4_ & 0xffff,&annce.capability);
  if ((nbr_ieee_addr.field_0.u64._4_4_ != 0 || annce.ieee_addr.field_0.u64._0_4_ != 0) &&
     ((nbr_ieee_addr.field_0.u64._4_4_ != -1 || (annce.ieee_addr.field_0.u64._0_4_ != -1)))) {
    uStack_2a = 0;
    ieee_addr.u64 = nwk_address_ref_by_short(annce.ieee_addr.field_0.u64._4_4_ & 0xffff,&uStack_2a);
    if (extraout_a0 == 0) {
      _existing_nwk_addr = 0;
      nbr_ieee_addr.field_0.u64._0_4_ = 0;
      ieee_addr.u64 = nwk_address_extended_by_ref(uStack_2a,&existing_nwk_addr);
      if ((extraout_a0_00 == 0) &&
         ((((_existing_nwk_addr != nbr_ieee_addr.field_0.u64._4_4_ ||
            (nbr_ieee_addr.field_0.u64._0_4_ != annce.ieee_addr.field_0.u64._0_4_)) &&
           (_existing_nwk_addr != 0 || nbr_ieee_addr.field_0.u64._0_4_ != 0)) &&
          ((_existing_nwk_addr != -1 || (nbr_ieee_addr.field_0.u64._0_4_ != -1)))))) {
        ieee_addr.u64 = core_globals_get();
        if ((uint)uStack_2a < (uint)*(ushort *)(extraout_a0_01 + 0xcb8)) {
          *(undefined2 *)(*(int *)(extraout_a0_01 + 0xcb4) + (uint)uStack_2a * 0x10 + 6) = 0xffff;
        }
      }
    }
  }
  zdo_device_annce_indication
            ((ezb_extaddr_t)ieee_addr,(uint16_t)nbr_ieee_addr.field_0.u64._4_4_,
             (uint8_t)annce.ieee_addr.field_0.u64._0_4_);
  return 0xfe;
}

