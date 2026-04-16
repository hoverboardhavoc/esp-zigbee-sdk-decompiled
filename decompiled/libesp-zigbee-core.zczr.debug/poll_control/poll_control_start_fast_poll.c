/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_start_fast_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void poll_control_start_fast_poll(uint8_t ep_id,uint32_t timeout_ms)

{
  uint uVar1;
  zcl_attr_desc_t *pzVar2;
  
  pzVar2 = poll_control_srv_get_attr_desc(ep_id,2);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x5b,
                  "poll_control_start_fast_poll","attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar1 = (uint)*pzVar2->data_p * 0xfa;
    if (uVar1 != 0) {
      nwk_pim_set_fast_poll_interval(uVar1);
      nwk_pim_start_fast_poll(timeout_ms / uVar1 & 0xffff);
      return;
    }
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x5d,
                "poll_control_start_fast_poll","fast_poll_interval_ms > 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

