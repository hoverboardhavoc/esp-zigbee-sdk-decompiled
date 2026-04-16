/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_association_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_association_rsp(mac_device *dev,mac_frame_t *frame)

{
  mac_frame_t *extraout_a1;
  uint8_t *puVar1;
  mac_associate_cnf_t mStack_14;
  mac_associate_cnf_t asso_cnf;
  
  puVar1 = (frame->mpl).buf;
  if (*puVar1 == '\x02') {
    mStack_14.asso_shortaddr = *(ezb_shortaddr_t *)(puVar1 + 1);
    mStack_14.status = puVar1[3];
    if ((frame->mhr).src_addr.addr_mode != '\x03') goto _L0;
  }
  else {
    dev = (mac_device *)
          __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x3f8,"mac_handle_association_rsp",
                        "*cmd_ptr++ == 2U");
    frame = extraout_a1;
  }
  *(ezb_grpaddr_t *)&(dev->pib).coord_extaddr.field_0 = (frame->mhr).src_addr.u.group_addr;
  *(undefined4 *)((int)&(dev->pib).coord_extaddr.field_0 + 4) =
       *(undefined4 *)((int)&(frame->mhr).src_addr.u + 4);
_L0:
  mac_finish_association(dev,&mStack_14);
  return;
}

