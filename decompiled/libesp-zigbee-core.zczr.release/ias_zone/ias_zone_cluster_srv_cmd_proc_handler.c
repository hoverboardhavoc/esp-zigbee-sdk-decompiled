/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ias_zone_cluster_srv_cmd_proc_handler(uint param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ushort uStack_66;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined1 auStack_48 [52];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 == '\x01') {
    uStack_64 = 0;
    uStack_60 = 0;
    iVar2 = ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15));
    if ((*(char *)(iVar2 + 2) == '\0') ||
       (iVar2 = validate_cie_authorization
                          (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 2)), iVar2 == 0
       )) {
_L0:
      uVar4 = 0x7e;
      goto _L0;
    }
    uVar4 = zcl_packet_to_message(&uStack_64,param_1);
    if (uVar4 != 0) goto _L0;
    uStack_60._0_3_ = CONCAT12(0xfe,(undefined2)uStack_60);
    zcl_core_action_schedule(0x30,&uStack_64);
    uVar4 = uStack_60 >> 0x10 & 0xff;
    if (uVar4 != 0xfe) {
      puVar5 = (undefined1 *)ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15));
      iVar2 = milli_timer_is_running(puVar5 + 4);
      if (iVar2 != 0) {
        milli_timer_stop(puVar5 + 4);
      }
      iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x13);
      if (iVar2 == 0) goto _L85;
_L0:
      if (puVar5[1] != '\0') {
        **(undefined1 **)(iVar2 + 8) = *puVar5;
        puVar5[1] = 0;
      }
      goto _L0;
    }
  }
  else {
    if (cVar1 != '\x02') {
      uVar4 = 0x81;
      if (cVar1 == '\0') {
        uStack_64 = uStack_64 & 0xffff0000;
        uStack_5c = 0;
        uStack_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,&uStack_50);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_64,(int)&uStack_50 + 1);
        uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        uVar4 = 0x80;
        if ((uStack_64 & 0xffff) <= uVar3) {
          if ((uStack_50 & 0xff) == 0) {
            iVar2 = ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15),0x80);
            if ((*(char *)(iVar2 + 2) == '\0') ||
               (iVar2 = validate_cie_authorization
                                  (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 2)),
               iVar2 == 0)) {
              uVar4 = 0x7e;
              goto _L0;
            }
            iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x11);
            **(undefined1 **)(iVar2 + 8) = uStack_50._1_1_;
            iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0);
            **(undefined1 **)(iVar2 + 8) = 1;
          }
          uVar4 = zcl_packet_to_message(&uStack_5c,param_1);
          if (uVar4 == 0) {
            uStack_4c = CONCAT31(uStack_4c._1_3_,0xfe);
            uStack_54 = param_1;
            zcl_core_action_schedule(0x32,&uStack_5c,0);
            if ((uStack_4c & 0xff) != 0xfe) {
              uVar4 = uStack_4c & 0xff;
            }
          }
        }
      }
      goto _L0;
    }
    uStack_66 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = uStack_54 & 0xffff0000;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,(int)&uStack_58 + 2);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_66,(int)&uStack_58 + 3);
    uVar4 = 0x80;
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar3 < uStack_66) goto _L0;
    iVar2 = ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15));
    if ((*(char *)(iVar2 + 2) == '\0') ||
       (iVar2 = validate_cie_authorization
                          (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 2)), iVar2 == 0
       )) goto _L0;
    puVar5 = (undefined1 *)ias_zone_srv_get_zone_ctx(*(undefined1 *)(param_1 + 0x15));
    iVar2 = ias_zone_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x13);
    if (iVar2 == 0) {
_L85:
      iVar2 = __assert_func(0,0,0,0);
      goto _L0;
    }
    puVar6 = *(undefined1 **)(iVar2 + 8);
    *puVar5 = *puVar6;
    *puVar6 = uStack_58._3_1_;
    uVar4 = zcl_packet_to_message(&uStack_5c,param_1);
    if (uVar4 != 0) goto _L0;
    uStack_54 = CONCAT31(uStack_54._1_3_,0xfe);
    zcl_core_action_schedule(0x2f,&uStack_5c);
    uVar4 = uStack_54 & 0xff;
    if (uVar4 != 0xfe) {
      if (uVar4 == 0) {
        puVar5[1] = 1;
        milli_timer_init(ias_zone_restore_normal_operation_mode,*(undefined1 *)(param_1 + 0x15));
        milli_timer_start(puVar5 + 4,(uStack_58 >> 0x10 & 0xff) * 1000);
      }
      goto _L0;
    }
    **(undefined1 **)(iVar2 + 8) = *puVar5;
  }
  uVar4 = 1;
_L0:
  iVar2 = zcl_packet_setup_default_response(auStack_48,param_1,uVar4);
  if (iVar2 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar2;
}

