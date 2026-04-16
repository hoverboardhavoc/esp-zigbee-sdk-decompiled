/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_in_context_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_check_in_context_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  uint8_t *puVar2;
  
  pzVar1 = poll_control_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
    puVar2 = (uint8_t *)calloc(1,0x14);
    *puVar2 = ep_id;
    pzVar1->data_p = puVar2;
    milli_timer_init(puVar2 + 4,poll_control_check_in_timeout,puVar2);
  }
  return;
}

