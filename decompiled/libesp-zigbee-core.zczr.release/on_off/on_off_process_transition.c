/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> on_off.o -> on_off_process_transition
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_process_transition
               (undefined4 param_1,uint param_2,int param_3,short param_4,short param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  short *psVar6;
  short sStack_24;
  short asStack_22 [5];
  
  iVar1 = param_3;
  sStack_24 = param_5;
  asStack_22[0] = param_4;
  if (param_2 < 2) goto _L0;
  while( true ) {
    iVar1 = on_off_srv_get_attr_desc(param_1,0);
    iVar2 = on_off_srv_get_attr_desc(param_1,0x4001);
    iVar3 = on_off_srv_get_attr_desc(param_1,0x4002);
    if (iVar1 != 0) break;
    iVar1 = 0;
    __assert_func(0,0,0,0);
_L0:
    iVar1 = zcl_level_action_affect_by_on_off(iVar1 != 0);
    if (iVar1 != 0) {
      return;
    }
  }
  if ((iVar2 == 0) || (iVar3 == 0)) {
    bVar4 = param_3 != 0;
    goto _L0;
  }
  if (**(char **)(iVar1 + 8) == '\x01') {
    if (**(short **)(iVar2 + 8) == 0) {
      if (**(short **)(iVar3 + 8) != 0) goto _L0;
      if (param_2 != 0x40) {
        if (param_2 == 0x42) goto _L0;
        if (param_2 != 0) {
          return;
        }
      }
      bVar4 = false;
_L0:
      zcl_message_on_off_set_attr_value_isra_0(param_1,bVar4);
      return;
    }
    if (**(short **)(iVar3 + 8) != 0) {
      if (param_2 != 0x40) {
        if (param_2 == 0x42) {
          if (asStack_22[0] != 0) goto _L0;
          sStack_24 = 0;
          bVar4 = false;
          goto _L0;
        }
        if (param_2 != 0) {
          return;
        }
      }
      asStack_22[0] = 0;
      zcl_message_on_off_set_attr_value_isra_0(param_1,0);
      psVar6 = asStack_22;
      uVar5 = 0x4001;
      goto _L0;
    }
_L0:
    bVar4 = param_3 != 0;
_L0:
    zcl_message_on_off_set_attr_value_isra_0(param_1,bVar4);
_L0:
    on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
  }
  else {
    if ((**(char **)(iVar1 + 8) != '\0') || (**(short **)(iVar2 + 8) != 0)) goto _L0;
    if (**(short **)(iVar3 + 8) == 0) {
      if (param_2 != 0x41) {
        if (param_2 == 0x42) goto _L0;
        if (param_2 != 1) {
          return;
        }
      }
      bVar4 = true;
      goto _L0;
    }
    if (param_2 != 0x41) {
      if (param_2 == 0x42) {
        asStack_22[0] = 0;
        goto _L0;
      }
      if (param_2 != 1) {
        return;
      }
    }
    sStack_24 = 0;
    zcl_message_on_off_set_attr_value_isra_0(param_1,1);
  }
  psVar6 = &sStack_24;
  uVar5 = 0x4002;
_L0:
  on_off_srv_set_attr_value(param_1,uVar5,psVar6);
  return;
}

