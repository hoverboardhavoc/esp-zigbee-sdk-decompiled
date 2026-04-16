/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_check_in_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_check_in_start(uint8_t ep_id)

{
  uint8_t *puVar1;
  zcl_attr_desc_t *pzVar2;
  uint16_t in_a1;
  
  pzVar2 = poll_control_srv_get_attr_desc(ep_id,in_a1);
  if (((pzVar2 != (zcl_attr_desc_t *)0x0) &&
      (puVar1 = (uint8_t *)pzVar2->data_p, puVar1 != (uint8_t *)0x0)) &&
     (pzVar2 = poll_control_srv_get_attr_desc(*puVar1,0), pzVar2 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
    milli_timer_start(puVar1 + 4,*pzVar2->data_p * 0xfa);
    return;
  }
  return;
}

