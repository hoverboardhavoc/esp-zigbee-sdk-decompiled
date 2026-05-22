/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> door_lock_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000102ce) */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t door_lock_cluster_srv_cmd_proc_handler(void *arg)

{
  int iVar1;
  ezb_zcl_status_t eVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  byte abStack_3c [4];
  zcl_packet_tx_option_t tx_option;
  zcl_packet_t rsp;
  
  _tx_option = 0;
  abStack_3c[0] = 0;
  if (arg == (void *)0x0) {
    iVar1 = 1;
    goto _L0;
  }
  if ((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) {
    iVar1 = 1;
    goto _L0;
  }
  iVar1 = zcl_packet_init(&tx_option,*(byte *)((int)arg + 0x1a) >> 2 & 1);
  if (iVar1 != 0) goto _L0;
  iVar1 = ezb_zcl_get_attr_desc(*(undefined1 *)((int)arg + 0x15),0x101,1,0x34,0);
  if (iVar1 == 0) {
_L0:
    iVar1 = 0;
  }
  else if (**(char **)(iVar1 + 8) == '\0') {
    iVar1 = 1;
  }
  else {
    if (**(char **)(iVar1 + 8) != '\x01') {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/door_lock.c",0xc6,
                    "door_lock_cluster_srv_cmd_proc_handler",&_L0);
      goto _L0;
    }
    iVar1 = 2;
  }
  iVar3 = zcl_packet_get_security(arg);
  if (iVar3 < iVar1) {
    iVar1 = 0xfe;
  }
  else {
    if (*(char *)((int)arg + 0x20) == '\0') {
      eVar2 = door_lock_cluster_lock_door_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&tx_option);
      iVar1 = CONCAT31(extraout_var,eVar2);
    }
    else if (*(char *)((int)arg + 0x20) == '\x01') {
      eVar2 = door_lock_cluster_unlock_door_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&tx_option);
      iVar1 = CONCAT31(extraout_var_00,eVar2);
    }
    else {
      iVar1 = zcl_packet_setup_default_response(&tx_option,arg,0x81);
    }
    if (iVar1 == 0) {
      iVar3 = zcl_packet_get_security(arg);
      abStack_3c[0] = abStack_3c[0] & 0xfe | iVar3 == 2;
      zcl_packet_send_with_ext(&tx_option,0,abStack_3c);
    }
    else {
      zcl_packet_free(&tx_option);
    }
  }
_L0:
  return (ezb_zcl_status_t)iVar1;
}

