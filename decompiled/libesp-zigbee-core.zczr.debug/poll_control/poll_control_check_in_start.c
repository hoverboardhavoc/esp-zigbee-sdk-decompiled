/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_in_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_check_in_start(uint8_t ep_id)

{
  poll_control_srv_check_in_ctx_t *ppVar1;
  zcl_attr_desc_t *pzVar2;
  
  ppVar1 = poll_control_check_in_context_get(ep_id);
  if ((ppVar1 != (poll_control_srv_check_in_ctx_t *)0x0) &&
     (pzVar2 = poll_control_srv_get_attr_desc(ppVar1->ep_id,0), pzVar2 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
    milli_timer_start(&ppVar1->timer,*pzVar2->data_p * 0xfa);
  }
  return;
}

