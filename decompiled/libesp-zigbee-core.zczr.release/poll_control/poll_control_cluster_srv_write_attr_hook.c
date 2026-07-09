/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_srv_write_attr_hook(undefined4 param_1,int param_2,int *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int extraout_a1;
  
  if (param_3 == (int *)0x0) {
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  if (param_2 == 1) {
    nwk_ed_set_keepalive_interval(*param_3 * 0xfa);
    return;
  }
  if (param_2 == 2) {
    nwk_pim_set_fast_poll_interval(*param_3 * 0xfa);
    return;
  }
  if (param_2 != 0) {
    return;
  }
  iVar2 = poll_control_srv_get_attr_desc_part_0();
  if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {
    milli_timer_stop(*(int *)(iVar2 + 8) + 4);
  }
  iVar2 = poll_control_srv_get_attr_desc_part_0(param_1);
  if (((iVar2 != 0) && (puVar1 = *(undefined1 **)(iVar2 + 8), puVar1 != (undefined1 *)0x0)) &&
     (iVar2 = poll_control_srv_get_attr_desc(*puVar1,0), iVar2 != 0)) {
    milli_timer_start(puVar1 + 4,**(int **)(iVar2 + 8) * 0xfa);
    return;
  }
  return;
}

