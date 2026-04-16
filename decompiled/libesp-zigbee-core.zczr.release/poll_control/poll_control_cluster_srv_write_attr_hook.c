/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  uint8_t *puVar1;
  uint8_t extraout_a0;
  zcl_attr_desc_t *pzVar2;
  uint16_t extraout_a1;
  uint16_t attr_id_00;
  undefined2 in_register_0000202e;
  int iVar3;
  
  iVar3 = CONCAT22(in_register_0000202e,attr_id);
  if (new_value == (void *)0x0) {
    iVar3 = __assert_func(0,0,0);
    endpoint = extraout_a0;
  }
                    /* WARNING: Load size is inaccurate */
  if (iVar3 == 1) {
    nwk_ed_set_keepalive_interval(*new_value * 0xfa);
    return;
  }
  if (iVar3 == 2) {
    nwk_pim_set_fast_poll_interval(*new_value * 0xfa);
    return;
  }
  if (iVar3 != 0) {
    return;
  }
  pzVar2 = poll_control_srv_get_attr_desc(endpoint,0);
  attr_id_00 = extraout_a1;
  if ((pzVar2 != (zcl_attr_desc_t *)0x0) && (pzVar2->data_p != (void *)0x0)) {
    attr_id_00 = milli_timer_stop((int)pzVar2->data_p + 4);
  }
  pzVar2 = poll_control_srv_get_attr_desc(endpoint,attr_id_00);
  if (((pzVar2 != (zcl_attr_desc_t *)0x0) &&
      (puVar1 = (uint8_t *)pzVar2->data_p, puVar1 != (uint8_t *)0x0)) &&
     (pzVar2 = poll_control_srv_get_attr_desc(*puVar1,0), pzVar2 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
    milli_timer_start(puVar1 + 4,*pzVar2->data_p * 0xfa);
    return;
  }
  return;
}

