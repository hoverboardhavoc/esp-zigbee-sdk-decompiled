/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  int extraout_a0;
  int extraout_a0_00;
  uint16_t *offset_00;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 ieee_addr;
  int local_20;
  zdp_device_annce_t annce;
  uint16_t offset;
  
  annce.nwk_addr = 0;
  local_20 = 0;
  annce.ieee_addr.field_0.u64._0_4_ = 0;
  annce.ieee_addr.field_0.u64._4_4_ = 0;
  if ((packet != (zdo_packet_t *)0x0) && (packet->payload != (zdo_packet_payload_t *)0x0)) {
    uVar1 = zmsg_get_length();
    offset_00 = &annce.nwk_addr;
    af_read_le16(packet->payload,offset_00,(uint16_t *)(annce.ieee_addr.field_0.u8 + 4));
    af_read_bytes(packet->payload,offset_00,8,(uint8_t *)&local_20);
    af_read_le8(packet->payload,offset_00,annce.ieee_addr.field_0.u8 + 6);
    if (annce.nwk_addr <= uVar1) {
      piVar2 = (int *)nwk_get_extended_address();
      if ((*piVar2 != local_20) || (piVar2[1] != annce.ieee_addr.field_0.u64._0_4_)) {
        ieee_addr.u64 = nwk_is_device_zczr();
        if (extraout_a0 != 0) {
          annce.capability = '\0';
          annce._11_1_ = 0;
          ieee_addr.u64 =
               nwk_address_update(&local_20,annce.ieee_addr.field_0.u64._4_4_ & 0xffff,
                                  &annce.capability);
          if (extraout_a0_00 == 0xd) {
            nwk_raise_address_conflict(annce.ieee_addr.field_0.u64._4_2_);
            return 0xfe;
          }
        }
        zdo_device_annce_indication
                  ((ezb_extaddr_t)ieee_addr,(uint16_t)local_20,
                   (uint8_t)annce.ieee_addr.field_0.u64._0_4_);
      }
    }
  }
  return 0xfe;
}

