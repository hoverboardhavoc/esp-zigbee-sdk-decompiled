/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_association_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_association_req(mac_device *dev,mac_frame_t *frame)

{
  mac_frame_t *extraout_a1;
  uint8_t *puVar1;
  ezb_grpaddr_t eStack_1c;
  mac_associate_ind_t asso_ind;
  
  puVar1 = (frame->mpl).buf;
  if (*puVar1 == '\x01') {
    if ((frame->mhr).src_addr.addr_mode != '\x03') {
      return;
    }
  }
  else {
    dev = (mac_device *)
          __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x422,"mac_handle_association_req",
                        "*cmd_ptr++ == 1U");
    frame = extraout_a1;
  }
  eStack_1c = (frame->mhr).src_addr.u.group_addr;
  asso_ind.device_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(frame->mhr).src_addr.u + 4);
  asso_ind.device_address.field_0.u8[4] = puVar1[1];
  nwk_mm_asso_indication((dev->ctx).iface_id,&eStack_1c);
  return;
}

