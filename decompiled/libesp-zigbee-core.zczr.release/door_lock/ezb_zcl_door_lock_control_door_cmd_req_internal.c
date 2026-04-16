/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> ezb_zcl_door_lock_control_door_cmd_req_internal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_door_lock_control_door_cmd_req_internal
                    (ezb_zcl_cluster_cmd_ctrl_t *cmd_ctrl,_Bool aps_secur_enabled,uint8_t cmd_id)

{
  void *in_a0;
  int iVar1;
  undefined3 in_register_00002031;
  undefined1 auStack_60 [20];
  byte abStack_4c [4];
  zcl_packet_tx_option_t tx_option;
  zcl_packet_t packet;
  
  memset(&tx_option,0,0x28);
  abStack_4c[0] = 0;
  iVar1 = zcl_packet_init(&tx_option,0);
  if (iVar1 == 0) {
    memcpy(auStack_60,in_a0,10);
    iVar1 = zcl_cmd_to_packet(&tx_option,0,0,*(undefined1 *)((int)in_a0 + 0xc),0,
                              CONCAT31(in_register_00002031,cmd_id),0x101);
    if (iVar1 == 0) {
      abStack_4c[0] = abStack_4c[0] & 0xfe | aps_secur_enabled;
      zcl_packet_send_with_ext(&tx_option,(int)in_a0 + 0x10,abStack_4c);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(&tx_option);
  return iVar1;
}

