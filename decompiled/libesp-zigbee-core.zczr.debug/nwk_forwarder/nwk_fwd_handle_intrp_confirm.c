/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_intrp_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_fwd_handle_intrp_confirm(uint8_t iface_id,mac_data_cnf_t *cnf)

{
  zmsg_t *pzVar1;
  uint uVar2;
  ushort auStack_12 [2];
  uint16_t fcf;
  
  pzVar1 = cnf->msdu;
  auStack_12[0] = 0;
  if (pzVar1 == (zmsg_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x3e2,
                  "nwk_fwd_handle_intrp_confirm",&_L0);
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_forwarder.c",0x3e6,
                  "nwk_fwd_handle_intrp_confirm","nwk_fcf_get_frame_type(fcf) == NWK_FRAME_INTRP");
  }
  else {
    zmsg_read_bytes(pzVar1,0,2,auStack_12);
    if ((auStack_12[0] & 3) != 3) goto _L0;
    if (cnf->status != 0) {
      uVar2 = cnf->status | 0x200;
      goto _L0;
    }
  }
  uVar2 = 0;
_L0:
  nwk_handle_intrp_data_sent(pzVar1,uVar2);
  return;
}

